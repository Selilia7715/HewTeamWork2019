#include "Camera.h"
using namespace DirectX;

Camera::Camera():
	m_position(0.f,0.f,0.f),
	m_look(0.f,0.f,1.f),
	m_up(0.f,1.f,0.f),
	m_right(1.f,0.f,0.f)
{
	SetLens(0.25*XM_PI, 800.f / 600, 1.f, 1000.f);
}

//����ͶӰ����
void Camera::SetLens(float fovY, float aspect, float nearz, float farz)
{
	m_fovY = fovY;
	m_aspect = aspect;
	m_nearZ = nearz;
	m_farZ = farz;
	XMMATRIX P = XMMatrixPerspectiveFovLH(fovY, aspect, nearz, farz);
	XMStoreFloat4x4(&m_proj, P);
}

//�����ӽǾ���
void Camera::LookAtXM(DirectX::FXMVECTOR pos, DirectX::FXMVECTOR lookAt, DirectX::FXMVECTOR worldUp)
{
	XMVECTOR look = XMVector3Normalize(lookAt - pos);
	XMVECTOR right = XMVector3Normalize(XMVector3Cross(worldUp, look));
	XMVECTOR up = XMVector3Cross(look, right);

	XMStoreFloat3(&m_position, pos);
	XMStoreFloat3(&m_look, look);
	XMStoreFloat3(&m_right, right);
	XMStoreFloat3(&m_up, up);
}

void Camera::LookAt(const DirectX::XMFLOAT3& pos, const DirectX::XMFLOAT3& lookAt, 
	const DirectX::XMFLOAT3& worldUp)
{
	XMVECTOR p = XMLoadFloat3(&pos);
	XMVECTOR l = XMLoadFloat3(&lookAt);
	XMVECTOR u = XMLoadFloat3(&worldUp);

	LookAtXM(p, l, u);
}

//ǰ������
void Camera::Walk(float dist)
{
	XMVECTOR pos = XMLoadFloat3(&m_position);
	XMVECTOR look = XMLoadFloat3(&m_look);
	pos += look * XMVectorReplicate(dist); //XMVectorReplicate(x)����XMVector(x,x,x,x)
	XMStoreFloat3(&m_position, pos);
}

//����ƽ��
void Camera::Strafe(float dist)
{
	XMVECTOR pos = XMLoadFloat3(&m_position);
	XMVECTOR right = XMLoadFloat3(&m_right);
	pos += right * XMVectorReplicate(dist);

	XMStoreFloat3(&m_position, pos);
}

//���µ�ͷ
void Camera::Pitch(float angle)
{
	XMMATRIX rotation = XMMatrixRotationAxis(XMLoadFloat3(&m_right), angle);
							//�����������
	XMStoreFloat3(&m_up, XMVector3TransformNormal(XMLoadFloat3(&m_up), rotation));
	XMStoreFloat3(&m_look, XMVector3TransformNormal(XMLoadFloat3(&m_look), rotation));
}

//����ҡͷ
void Camera::RotateY(float angle)
{
	XMMATRIX rotation = XMMatrixRotationY(angle);

	XMStoreFloat3(&m_right, XMVector3TransformNormal(XMLoadFloat3(&m_right), rotation));
	XMStoreFloat3(&m_up, XMVector3TransformNormal(XMLoadFloat3(&m_up), rotation));
	XMStoreFloat3(&m_look, XMVector3TransformNormal(XMLoadFloat3(&m_look), rotation));
}

//�����ӽǾ���
void Camera::UpdateViewMatrix()
{
	XMVECTOR r = XMLoadFloat3(&m_right);
	XMVECTOR u = XMLoadFloat3(&m_up);
	XMVECTOR l = XMLoadFloat3(&m_look);
	XMVECTOR p = XMLoadFloat3(&m_position);

	r = XMVector3Normalize(XMVector3Cross(u, l));
	u = XMVector3Normalize(XMVector3Cross(l, r));
	l = XMVector3Normalize(l);

	float x = -XMVectorGetX(XMVector3Dot(p, r));
	float y = -XMVectorGetX(XMVector3Dot(p, u));
	float z = -XMVectorGetX(XMVector3Dot(p, l));

	XMStoreFloat3(&m_right, r);
	XMStoreFloat3(&m_up, u);
	XMStoreFloat3(&m_look, l);
	XMStoreFloat3(&m_position, p);

	m_view(0, 0) = m_right.x;	m_view(0, 1) = m_up.x;	m_view(0, 2) = m_look.x;	 m_view(0, 3) = 0;
	m_view(1, 0) = m_right.y;	m_view(1, 1) = m_up.y;	m_view(1, 2) = m_look.y; m_view(1, 3) = 0;
	m_view(2, 0) = m_right.z;	m_view(2, 1) = m_up.z;	m_view(2, 2) = m_look.z; m_view(2, 3) = 0;
	m_view(3, 0) = x;			m_view(3, 1) = y;		m_view(3, 2) = z;		 m_view(3, 3) = 1;
}

